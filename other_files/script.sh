#!/bin/bash

show_help() {
    echo "Usage: $0 [options] [directory]"
    echo
    echo "Checks if files in directory are executable"
    echo
    echo "Options:"
    echo "  -h         Show help"
    echo "  -d <num>   Depth of recursion"
    echo "  -r         Search recursively"
    echo
    exit 0
}

depth=1
recursive=false

while getopts "hrd:" opt; do
    case $opt in
        h)
            show_help
            ;;
        r)
            recursive=true
            ;;
        d)
            depth=$OPTARG
            ;;
        \?)
            echo "Unknown option: -$OPTARG" >&2
            show_help
            ;;
    esac
done

shift $((OPTIND-1))

# Pass directory as a paramater(Use current if not passed)
path="${1:-.}"

# If more than one parameter is given
if [ $# -gt 1 ]; then
    echo "Parameter should be only one directory" >&2 
    exit 1
# If not a directory
elif [ ! -d "$path" ]; then
    echo "$path is not a directory" >&2 
    exit 1
fi

# Check passed flags
if [ "$recursive" = true ]; then
    cmd=( find "$path" -type f -o -type l )
else
    cmd=( find "$path" -maxdepth "$depth" -type f -o -type l )
fi

# Display info
"${cmd[@]}" | while read -r file; do
    if [ -L "$file" ]; then
        echo "File $file is soft link -> $(readlink "$file")"
    elif [ -x "$file" ]; then
        echo "File $file is executable"
    else
        echo "File $file is not executable"
    fi
done