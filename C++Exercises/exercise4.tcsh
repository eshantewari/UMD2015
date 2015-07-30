#!/bin/tcsh

set month = `date | awk '{print $2}'`
    echo $month

ls -lat | grep "$month"
