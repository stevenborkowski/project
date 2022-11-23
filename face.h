#define PY_SSIZE_T_CLEAN
#define PY_MODULE_NAME "face.py"
#define PY_TRAIN_FUNC "train_model"
#define PY_PROCIM_FUNC "process_input"
#define PY_PREDICT_FUNC "make_prediction"
#include <Python.h>

void Face_initialize();
int Face_recognize();
void Face_cleanup();