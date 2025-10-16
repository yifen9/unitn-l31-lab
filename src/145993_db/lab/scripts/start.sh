#!/usr/bin/env bash
set -e

COMPOSE_FILE="../compose.yaml"

echo "Pulling latest images..."
docker-compose -f $COMPOSE_FILE pull

echo "Starting services with Docker Compose..."
docker-compose -f $COMPOSE_FILE up -d

echo "Services running:"
docker-compose -f $COMPOSE_FILE ps