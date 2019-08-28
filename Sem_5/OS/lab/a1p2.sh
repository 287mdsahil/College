no=$( find ./ -type f | wc -l )
echo "Total no files under curret directory :- " $no


echo
echo "Sub directories with no of files :- "
find . -type d | while read dir; do
    no=$(find "$dir" -type f | wc -l)
    echo $dir "  no of files :-  " $no
done

echo
echo "Files created within the last 2 days :- "
find . -type f -mtime -2
