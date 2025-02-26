#!/bin/sh

echo "Starting server on port 12345"

while true; do
  echo "Waiting for connection..."
  
  nc -l -p 12345

done