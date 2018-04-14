# Error Level Analysis

### What is ELA?

The basic idea of ELA is to identify parts of the images that vary in compression levels. It can be used to find parts of the images that are tampered.

### Algorithm

1) Open the Target Image
2) Compress the image to a known quality level
3) Compute the difference between the original and the compressed image

#### Inference:-

With JPEG images, the entire picture should be at roughly the same level. If a section of the image is at a significantly different error level, then it likely indicates a digital modification.

#### Steps to run

```
sudo python setup.py install
```


```
python ela_test.py 
```

### References

[Digital Image Analysis and Forensics](http://blackhat.com/presentations/bh-dc-08/Krawetz/Whitepaper/bh-dc-08-krawetz-WP.pdf)

[fotoforensics.com](https://fotoforensics.com/tutorial-ela.php)
