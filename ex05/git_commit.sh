for i in 1 2 3 4 5
do
	echo $(git log HEAD~$i..HEAD~$(($i - 1)) --pretty=format:'%H')
done

