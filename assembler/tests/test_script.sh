#!/bin/bash


read -p "Please specify the relative path to asm you want to compare with ours`echo $'\n> '`" path_other_asm
read -p "Now enter the name of the executable `echo $'\n> '`" name_other_asm

echo "$path_other_asm/$name_other_asm\n"

if [ ! -f "$path_other_asm/$name_other_asm" ]
then
	echo "Invalid path/name, please try again later\n"
	exit 1
fi

tests_dir="./champs"
my_champs_dir="./our_asm"
other_champs_dir="./srcs_asm"

mkdir -p $my_champs_dir
mkdir -p $other_champs_dir

files=($(ls ./$tests_dir))

for champ in "${files[@]}"
do
	:
	./../asm $champ
done

mv *.cor $my_champs_dir
rm -rf *.s

for champ in "${files[@]}"
do
	:
	./$path_other_asm/$name_other_asm $champ
done

mv *.cor $other_champs_dir
rm -rf *.s

for champ in "${files[@]}"
do
	:
	cmp "$my_champs_dir/${champ%.s}.cor" "$other_champs_dir/${champ%.s}.cor" 
done
