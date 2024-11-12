#!/bin/bash
if (("$3")) 
    then 
        rm *.tar.gz

        for ((i= $2 ; i <= $3; i++))
        do
            tar -cvf esercizio$1.$i.tar esercizio$1.$i
            gzip esercizio$1.$i.tar
        done

        cp *.tar.gz /home/comune/labTNDS_aa2425_esercizi/Turno_T1/frigerio_30906A

    else 

        echo usage :  $0  \< numero lezione \> \< numero primo esercizio \>  \< numero ultimo esercizio \> 
        exit 1
fi