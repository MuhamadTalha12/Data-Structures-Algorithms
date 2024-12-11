import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('Train.csv')

print(df.dtypes)

x = df['COUGH'].values.tolist()
y = df['TYPE'].values.tolist()

plt.scatter(x,y)
plt.show()