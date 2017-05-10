#!/bin/bash
./t1 encode -i dna.50MB -o dnaBwt100.50MB --bwt=true --txtblck=100 --huffman=false --runl=false > 50mbBwt100.out
./t1 encode -i dna.50MB -o dnaBwt500.50MB --bwt=true --txtblck=500 --huffman=false --runl=false > 50mbBwt500.out
./t1 encode -i dna.50MB -o dnaBwt1000.50MB --bwt=true --txtblck=1000 --huffman=false --runl=false > 50mbBwt1000.out
./t1 encode -i dna.50MB -o dnaBwt10000.50MB --bwt=true --txtblck=10000 --huffman=false --runl=false > 50mbBwt10000.out
./t1 encode -i dna.100MB -o dnaBwt100.100MB --bwt=true --txtblck=100 --huffman=false --runl=false > 100mbBwt100.out
./t1 encode -i dna.100MB -o dnaBwt500.100MB --bwt=true --txtblck=500 --huffman=false --runl=false > 100mbBwt500.out
./t1 encode -i dna.100MB -o dnaBwt1000.100MB --bwt=true --txtblck=1000 --huffman=false --runl=false > 100mbBwt1000.out
./t1 encode -i dna.100MB -o dnaBwt10000.100MB --bwt=true --txtblck=10000 --huffman=false --runl=false > 100mbBwt10000.out
./t1 encode -i dna.200MB -o dnaBwt100.200MB --bwt=true --txtblck=100 --huffman=false --runl=false > 200mbBwt100.out
./t1 encode -i dna.200MB -o dnaBwt500.200MB --bwt=true --txtblck=500 --huffman=false --runl=false > 200mbBwt500.out
./t1 encode -i dna.200MB -o dnaBwt1000.200MB --bwt=true --txtblck=1000 --huffman=false --runl=false > 200mbBwt1000.out
./t1 encode -i dna.200MB -o dnaBwt10000.200MB --bwt=true --txtblck=10000 --huffman=false --runl=false > 200mbBwt10000.out

./t1 encode -i dna.50MB -o dnaBwtRl100.50MB --bwt=true --txtblck=100 --huffman=false --runl=true > 50mbBwtRl100.out
./t1 encode -i dna.50MB -o dnaBwtRl500.50MB --bwt=true --txtblck=500 --huffman=false --runl=true > 50mbBwtRl500.out
./t1 encode -i dna.50MB -o dnaBwtRl1000.50MB --bwt=true --txtblck=1000 --huffman=false --runl=true > 50mbBwtRl1000.out
./t1 encode -i dna.50MB -o dnaBwtRl10000.50MB --bwt=true --txtblck=10000 --huffman=false --runl=true > 50mbBwtRl10000.out
./t1 encode -i dna.100MB -o dnaBwtRl100.100MB --bwt=true --txtblck=100 --huffman=false --runl=true > 100mbBwtRl100.out
./t1 encode -i dna.100MB -o dnaBwtRl500.100MB --bwt=true --txtblck=500 --huffman=false --runl=true > 100mbBwtRl500.out
./t1 encode -i dna.100MB -o dnaBwtRl1000.100MB --bwt=true --txtblck=1000 --huffman=false --runl=true > 100mbBwtRl1000.out
./t1 encode -i dna.100MB -o dnaBwtRl10000.100MB --bwt=true --txtblck=10000 --huffman=false --runl=true > 100mbBwtRl10000.out
./t1 encode -i dna.200MB -o dnaBwtRl100.200MB --bwt=true --txtblck=100 --huffman=false --runl=true > 200mbBwtRl100.out
./t1 encode -i dna.200MB -o dnaBwtRl500.200MB --bwt=true --txtblck=500 --huffman=false --runl=true > 200mbBwtRl500.out
./t1 encode -i dna.200MB -o dnaBwtRl1000.200MB --bwt=true --txtblck=1000 --huffman=false --runl=true > 200mbBwtRl1000.out
./t1 encode -i dna.200MB -o dnaBwtRl10000.200MB --bwt=true --txtblck=10000 --huffman=false --runl=true > 200mbBwtRl10000.out

./t1 encode -i dna.50MB -o dnaBwtHRl100.50MB --bwt=true --txtblck=100 --huffman=true --runl=true > 50mbBwtHRl100.out
./t1 encode -i dna.50MB -o dnaBwtHRl500.50MB --bwt=true --txtblck=500 --huffman=true --runl=true > 50mbBwtHRl500.out
./t1 encode -i dna.50MB -o dnaBwtHRl1000.50MB --bwt=true --txtblck=1000 --huffman=true --runl=true > 50mbBwtHRl1000.out
./t1 encode -i dna.50MB -o dnaBwtHRl10000.50MB --bwt=true --txtblck=10000 --huffman=true --runl=true > 50mbBwtHRl10000.out
./t1 encode -i dna.100MB -o dnaBwtHRl100.100MB --bwt=true --txtblck=100 --huffman=true --runl=true > 100mbBwtHRl100.out
./t1 encode -i dna.100MB -o dnaBwtHRl500.100MB --bwt=true --txtblck=500 --huffman=true --runl=true > 100mbBwtHRl500.out
./t1 encode -i dna.100MB -o dnaBwtHRl1000.100MB --bwt=true --txtblck=1000 --huffman=true --runl=true > 100mbBwtHRl1000.out
./t1 encode -i dna.100MB -o dnaBwtHRl10000.100MB --bwt=true --txtblck=10000 --huffman=true --runl=true > 100mbBwtHRl10000.out
./t1 encode -i dna.200MB -o dnaBwtHRl100.200MB --bwt=true --txtblck=100 --huffman=true --runl=true > 200mbBwtHRl100.out
./t1 encode -i dna.200MB -o dnaBwtHRl500.200MB --bwt=true --txtblck=500 --huffman=true --runl=true > 200mbBwtHRl500.out
./t1 encode -i dna.200MB -o dnaBwtHRl1000.200MB --bwt=true --txtblck=1000 --huffman=true --runl=true > 200mbBwtHRl1000.out
./t1 encode -i dna.200MB -o dnaBwtHRl10000.200MB --bwt=true --txtblck=10000 --huffman=true --runl=true > 200mbBwtHRl10000.out

./t1 encode -i dna.50MB -o dnaBwtH100.50MB --bwt=true --txtblck=100 --huffman=true --runl=false > 50mbBwtH100.out
./t1 encode -i dna.50MB -o dnaBwtH500.50MB --bwt=true --txtblck=500 --huffman=true --runl=false > 50mbBwtH500.out
./t1 encode -i dna.50MB -o dnaBwtH1000.50MB --bwt=true --txtblck=1000 --huffman=true --runl=false > 50mbBwtH1000.out
./t1 encode -i dna.50MB -o dnaBwtH10000.50MB --bwt=true --txtblck=10000 --huffman=true --runl=false > 50mbBwtH10000.out
./t1 encode -i dna.100MB -o dnaBwtH100.100MB --bwt=true --txtblck=100 --huffman=true --runl=false > 100mbBwtH100.out
./t1 encode -i dna.100MB -o dnaBwtH500.100MB --bwt=true --txtblck=500 --huffman=true --runl=false > 100mbBwtH500.out
./t1 encode -i dna.100MB -o dnaBwtH1000.100MB --bwt=true --txtblck=1000 --huffman=true --runl=false > 100mbBwtH1000.out
./t1 encode -i dna.100MB -o dnaBwtH10000.100MB --bwt=true --txtblck=10000 --huffman=true --runl=false > 100mbBwtH10000.out
./t1 encode -i dna.200MB -o dnaBwtH100.200MB --bwt=true --txtblck=100 --huffman=true --runl=false > 200mbBwtH100.out
./t1 encode -i dna.200MB -o dnaBwtH500.200MB --bwt=true --txtblck=500 --huffman=true --runl=false > 200mbBwtH500.out
./t1 encode -i dna.200MB -o dnaBwtH1000.200MB --bwt=true --txtblck=1000 --huffman=true --runl=false > 200mbBwtH1000.out
./t1 encode -i dna.200MB -o dnaBwtH10000.200MB --bwt=true --txtblck=10000 --huffman=true --runl=false > 200mbBwtH10000.out

./t1 encode -i dna.50MB -o dnaHRl.50MB --bwt=false --txtblck=100 --huffman=true --runl=true > 50mbHRl.out
./t1 encode -i dna.50MB -o dnaHRl.100MB --bwt=false --txtblck=100 --huffman=true --runl=true > 100mbHRl.out
./t1 encode -i dna.50MB -o dnaHRl.200MB --bwt=false --txtblck=100 --huffman=true --runl=true > 200mbHRl.out