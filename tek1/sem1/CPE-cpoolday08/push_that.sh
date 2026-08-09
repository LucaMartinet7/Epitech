git add *

if [ -n "$1" ]
then
	git commit -am "$1"
else
	git commit -am "working cant lie"
fi

git push

