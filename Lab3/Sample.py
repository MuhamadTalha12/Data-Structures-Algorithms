import matplotlib.pyplot as plt
import pandas as pd
df = pd.read_csv('population.csv')
print(df.dtypes)
list1 = df['Country (or dependency)'].values.tolist()
list2 = df['Population (2020)'].values.tolist()
plt.bar(list1, list2,width = 1, color = ['red', 'green'])
# plt.plot(list1[:10],list2[:20])
plt.show()