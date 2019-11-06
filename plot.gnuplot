set datafile separator ","
set key autotitle columnheader
set style fill transparent solid 0.5 noborder
set style data histeps
set terminal png
set grid
set output 'out.png'
set ylabel "Number of occurrences"
set xlabel "Hash"
set title "Krytaya laba po proge"
plot for [i=5:7] "ofile.csv" using i
