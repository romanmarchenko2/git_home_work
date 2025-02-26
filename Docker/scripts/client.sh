#!/bin/sh

echo "Starting client"

sleep 2

echo "Hello from client" | nc server 12345

echo "End client..."

tail -f /dev/null