## How to build images
Commands: 
```bash
docker build -t client .
docker build -t server .
```

## How to create network
Command:
```bash
docker network create custom_network
```

## How to run containers

### Interactive mode
Stop and remove existing containers (if needed):
```bash
docker stop server client || true
docker rm server client || true
```

Server:
```bash
docker run -it --rm --name server --network custom_network -v "$(pwd)/scripts:/scripts" server sh
```

Client:
```bash
docker run -it --rm --name client --network custom_network -v "$(pwd)/scripts:/scripts" client sh
```

### Detached mode with script execution
Server:
```bash
docker run -d --name server --network custom_network -v "$(pwd)/scripts:/scripts" server sh /scripts/server.sh 
```

Client:
```bash
docker run -d --name client --network custom_network -v "$(pwd)/scripts:/scripts" client sh /scripts/client.sh
```

## Commands to verify containers connectivity
1. Check if both containers are in the same network
```bash
docker network inspect custom_network
```

2. Ping server from client container
```bash
docker exec -it client ping server
```

## Commands to verify netcat scripts
1. When running in interactive mode:
```bash
docker exec -it server sh /scripts/server.sh
docker exec -it client sh /scripts/client.sh
```

2. When running in detached mode with script execution, check logs:
```bash
docker logs server
docker logs client
```

## Cleanup
Stop and remove containers:
```bash
docker stop server client
docker rm server client
```

Remove network:
```bash
docker network rm custom_network
```

Remove images (optional):
```bash
docker rmi server client
```