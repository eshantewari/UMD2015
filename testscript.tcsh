#!/bin/tcsh                                                                                                       

# here we can put some comments                                                                                    
# this is a trivial script but can serve as an example                                                             
# a script can take inputs. These are assigned variable names $1, $2 etc                                           
# based on their position                                                                                          
# here we create an environmental variable ARG and assign to it the value of the first input                       

set ARG=$1
# here as a bug statement we echo out the value to the screen                      
echo $ARG
# here we have it look for all the files in /usr and its subdirectories that
# contain somewhere in the file name the string we inputed                                                                                                
find /usr -name "*$ARG*" -print