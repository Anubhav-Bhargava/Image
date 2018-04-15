import ela
import matplotlib.pyplot as plt

mobile_img=plt.imread(ela.myfunc("image.jpg"))
photoshop_img=plt.imread(ela.myfunc("photoshop.jpg"))


f = plt.figure()
f.add_subplot(1, 2, 2)
f.add_subplot(1, 2, 1)
plt.imshow(mobile_img)
f.add_subplot(1, 2, 2)
plt.imshow(photoshop_img)
f.text(.5, .05, 'Mobile Image & Photoshoped Image', ha='center')
plt.axis('off')

plt.show()
plt.waitforbuttonpress(0) 
plt.close(f)