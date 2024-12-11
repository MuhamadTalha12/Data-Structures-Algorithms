import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv('Train.csv')
test_df = pd.read_csv('Test.csv')

symptoms = df.columns[:-1]#//[COUGH,MUSCLE_ACHES,TIREDNESS,SORE_THROAT,RUNNY_NOSE,STUFFY_NOSE,FEVER,NAUSEA,VOMITING,DIARRHEA,SHORTNESS_OF_BREATH,DIFFICULTY_BREATHING,LOSS_OF_TASTE,LOSS_OF_SMELL,ITCHY_NOSE,ITCHY_EYES,ITCHY_MOUTH,ITCHY_INNER_EAR,SNEEZING,PINK_EYE]
label = df.columns[-1]#//TYPE

for symptom in symptoms:
    plt.scatter(symptom, label , data=df)
    plt.title('Scatter Plot Between ' + symptom + ' and ' + label)
    plt.xlabel(symptom)
    plt.ylabel(label)
    plt.show()
