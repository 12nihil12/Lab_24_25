rm *.tar.gz
for ((i=0; i <= $2; i++))
do
    tar -cvf esercizio$1.$i.tar esercizio$1.$i
    gzip esercizio$1.$i.tar
done

cp *.tar.gz /home/comune/labTNDS_aa2425_esercizi/Turno_T1/frigerio_30906A