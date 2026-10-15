echo "############"
echo "input output redirection examples"
echo "############"
echo "pipe, direct stdout of command to standard in to other command, to run chain of commands directly without temperay storage"
echo "example cat a test file then grep from it something"
cat testFile | grep -i 'worlD'
echo "example cat file then word count for number of lines wc -l"
cat testFile | wc -l

echo "###############"
echo "Redirect stdout to a file, overwrite or create the file > "
echo "overwitten file 1 " > file1
echo "overwitten file 2" > file1
cat file1
echo "##############"
echo "Redirect stdout to a file, append >>"
echo "append here 1" >> file1
echo "append here 2" >> file1
echo "cat the file afetr appending"
cat  file1
echo "##############"
echo "Redirect stderr to a file 2> "
ddd2 2> stderrorFile
echo " cat stderrorfile"
cat stderrorFile
echo "################"
echo "Redirect stderror and stdout to file &> "
echo "Excecute batch script that shall produce output in both stdout and stderr, redirect output to file"
./a.sh &> foe
echo " cat the output file here#####"
cat foe
echo "###############"
echo "Redirect stderr and stdout to &> /dev/null, to ignore the errors and the output of a command"
./a.sh &> /dev/null
