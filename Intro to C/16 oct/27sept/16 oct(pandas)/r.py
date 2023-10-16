import pandas as pd
import numpy as np
df = pd.DataFrame({'col1': ['e', 2, 3, 4], 'col2': [5, 6,
7, 8], 'col3': [1,2,3,'gbdbgdbg']}, index=['c', 'c', 'c', 'd'])
#print(df)
s = pd.DataFrame({'col1': pd.Series([.1, .2, .3, .4,
.5], index=[1,2,3,4,5]), 'col2':
pd.Series([1., 2., 3.], index=[1,3,6])})
#print(s)
data = np.zeros((2, ))#, dtype=[('Year', 'i4'),
#('Company', 'a12'), ('Share/Mutual Fund', 'f4')])
#print(data)
#data[:] = [(1907, 'TATA STEEL', 344.00), (2019, "TATA DIGITAL INDIA FUND", '19.14')]
#s = pd.DataFrame(data)
#print(s)

ED = pd.read_excel("ManHourData.xlsx",engine = 'openpyxl')
print(ED)