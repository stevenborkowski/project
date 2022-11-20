# project
**Setup**  
```  
pip install opencv-contrib-python  
pip install numpy  
```  
**face.py**  
Contains function *train_model()* that trains and returns an eigneface model, process_input() that crops input images to be tested by the model and make_prediction() that performs the prediction on these images.  
  
**training-data**  
This directory contains the AT&T facedatabase, as well as additional pictures added to train the model.  
  
All pictures input into the model for training and predicting must be 92x112, grayscale, .pgm files.  
  
Main.c is used to call the Python functions and store the result. Compile main.c with the following commands: 
```
gcc main.c -o main -I/usr/include/python3.9 -lpython3.9
```  
Some of the filepaths in main.c will have to be adjusted for whatever system the program is running on.
