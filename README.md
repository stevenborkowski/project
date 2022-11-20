# project
**Setup**  
```  
pip install opencv-contrib-python  
pip install numpy  
```  
**face.py**  
Contains functions *train_model()* that trains and returns an eigneface model, *process_input()* that crops input images to be tested by the model and *make_prediction()* that performs the prediction on these images.  
  
**training-data**  
This directory contains the AT&T facedatabase, as well as additional pictures added to train the model.  
  
All pictures input into the model for training and predicting must be 92x112, grayscale, .pgm files.  

**main.c**  
Used to call the afforementioned Python functions and store the results. Compile main.c with the following command: 
```
gcc main.c -o main -I/usr/include/python3.9 -lpython3.9
```  
The filepath defined in main.c will have to be adjusted for whatever system the program is running on.
