#!/usr/texbin/texcount
counts=$(texcount -merge -brief main.tex | head -c4)
date=$(date +%s)
humandate=$(date +"%d %m %Y %H %M")

echo $humandate $counts >> counts.dat

