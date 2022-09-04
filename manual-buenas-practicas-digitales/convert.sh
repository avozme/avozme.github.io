#!/bin/bash
pandoc index.md -t html -o index.html --template=/home/alfredo/Repos/avozme.github.io/manual-buenas-practicas-digitales/templates/clean_menu.html --toc
