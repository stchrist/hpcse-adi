make clean
make 

N=256
dt=1

label=(alpha beta gamma delta epsilon xi eta theta iota kappa lambda mu);
k=(0.046 0.046 0.055 0.055 0.055 0.061 0.063 0.060 0.060 0.063 0.065 0.065);
F=(0.007 0.020 0.024 0.030 0.019 0.024 0.035 0.042 0.050 0.050 0.040 0.050);

for index in {0..11}; do
#	echo -e "$N\n$NT\n$Du\n$Dv\n$dt\n${k[index]}\n${F[index]}\n${label[index]}" > "${label[index]}.txt"
	echo "Diffusion ${label[index]} with k=${k[index]} and F=${F[index]} ..."
#	./diffusion < "${label[index]}.txt"
    ./main -N $N --dt $dt -k ${k[index]} -F ${F[index]} --visualize
done
