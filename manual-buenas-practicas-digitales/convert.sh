#!/bin/bash
pandoc index.md -t html -o index.html --template=clean_menu.html --toc
