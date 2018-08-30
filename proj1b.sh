mkdir Dir1
cd Dir1
chmod 770 Dir1
cd ..
mkdir Dir2
cd Dir2
chmod 775
cd ..
touch Dir1/File1
cd Dir1
chmod 400 File1
cd ..
touch Dir2/File2
cd Dir2
chmod 640 File2
cd ..
cd Dir1
mkdir Dir3
cd Dir3
mkdir Dir4
chmod 750 Dir4
touch File4
chmod 666 File4
touch File3
chmod 200 File3
cd ..
chmod 000 Dir3
cd ..
