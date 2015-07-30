set ARG=$1
set MESSAGE = "Argument - "
echo $MESSAGE$ARG
grep -ri -l "*$ARG*" .