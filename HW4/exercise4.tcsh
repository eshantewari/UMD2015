#!/bin/tcsh

set month = `date | awk '{print $2}'`
    echo $month
set tmpday = `date | awk '{print $3}'`
    echo $tmpday

if ($tmpday < 10) then
    set today =  " $tmpday"
else
    set today = $tmpday
endif

echo $today

ls -lat | grep "$month"
