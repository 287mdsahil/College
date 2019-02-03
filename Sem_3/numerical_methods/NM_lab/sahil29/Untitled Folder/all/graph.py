import matplotlib.pyplot as plt





#bisection method---------------------------------------------
file = open("./data/bisection","rb")
data=file.read()
data=data.split()

for i in range(len(data)):
	data[i]=data[i].split(',')
	
ite=[]
error=[]
for i in range(len(data)):
	ite.append(data[i][0])
	error.append((float)(data[i][1]))
	
plt.plot(error,color="blue",label='bisection')




#regula falsie method----------------------------------------
file = open("./data/rf","rb")
data=file.read()
data=data.split()

for i in range(len(data)):
	data[i]=data[i].split(',')
	
ite=[]
error=[]
for i in range(len(data)):
	ite.append(data[i][0])
	error.append((float)(data[i][1]))
	
plt.plot(error,color="green",label='regula falsie')



#newton ralphson method----------------------------------------
file = open("./data/nr","rb")
data=file.read()
data=data.split()

for i in range(len(data)):
	data[i]=data[i].split(',')
	
ite=[]
error=[]
for i in range(len(data)):
	ite.append(data[i][0])
	error.append((float)(data[i][1]))
	
plt.plot(error,color="yellow",label='newton ralphson')


#secant----------------------------------------
file = open("./data/secant","rb")
data=file.read()
data=data.split()

for i in range(len(data)):
	data[i]=data[i].split(',')
	
ite=[]
error=[]
for i in range(len(data)):
	ite.append(data[i][0])
	error.append((float)(data[i][1]))
	
plt.plot(error,color="red",label='secant')



#regula falsie method----------------------------------------
file = open("./data/fixedpoint","rb")
data=file.read()
data=data.split()

for i in range(len(data)):
	data[i]=data[i].split(',')
	
ite=[]
error=[]
for i in range(len(data)):
	ite.append(data[i][0])
	error.append((float)(data[i][1]))
	
plt.plot(error,color="orange",label='fixed point iteration')


plt.legend()
plt.show()
