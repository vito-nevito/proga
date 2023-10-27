#!/bin/bash
git init proga
cd ./proga
git pull https://github.com/vito-nevito/proga
git branch -m main
git remote add origin https://github.com/vito-nevito/proga
git push -u origin main
