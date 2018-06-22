.name "Team Ningi"
.comment "Ningggiiiii"

label:	fork %3
		sti r1, %4, %4
		live %0
		add r1, r2, r2
		fork %:label
		sti r1, %200, %200
		sti r1, %100, %100
		sti r1, %50, %50
label2:	fork %3
		sti r1, %4, %4
		live %0
		add r1, r2, r2
		fork %:label2
