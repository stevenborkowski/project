# project
**Setup**  
```  
sudo apt update
sudo apt install python3-opencv
```  
**face.py**  
Contains functions *train_model()* that trains and returns an eigneface model, *process_input()* that crops input images to be tested by the model and *make_prediction()* that performs the prediction on these images.  
  
**training-data**  
This directory contains the AT&T facedatabase, as well as additional pictures added to train the model.  
  
All pictures input into the model for training and predicting must be 92x112, grayscale, .pgm files.  

**face.c**  
Contains functions to call Python python functions using embedded Python api.

**main.c**  
Used to call functions from *face.c* and store the results. Compile main.c with the following command: 
```
gcc face.c main.c -o main -I/usr/include/python3.9 -lpython3.9
```  
Works independent of path. The only thing to be adjusted on different devices is in line 33 of **face.py**. "test3.pgm" must be changed to the name of whatever the program will label input images as.
