module load nodejs
node-gyp build
if [ $? -eq 0 ];
then
    node test
fi
