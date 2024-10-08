#!/bin/bash

IMAGE_NAME="my_image_for_test"

echo "ТЕСТЫ S21_STRING"

echo "Сборка Docker образа..."
sudo docker build -t $IMAGE_NAME . 
echo "Сборка Docker завершена"

echo "Запуск контейнера..."
sudo docker run --rm $IMAGE_NAME

echo "Удаление образа..."
sudo docker rmi --force $IMAGE_NAME
echo "Образ удален"