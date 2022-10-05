# DCT_DATA_Compression1

An assignment given in the course Wireless Sensor Networks, to implement Discrete Cosine Transform to transform time-series data or an image to its frequency domain. This is to be implemeted in C, and then uploaded to a TelosB Mote.

We are given a DCT matrix (H), and I have chosen to pre-store it in the mote.

The DCT transformation written in the matrix form:
<img width="472" alt="image" src="https://user-images.githubusercontent.com/43139396/194112230-dc1919ab-62ce-42a7-9e17-a2ca8b1027f6.png">

The study part of the assignment is to implement the DCT matrix, and run it on the TelosB mote, to test the processing time. We will try to see the difference in processing time, when we try different values for L, and see the difference in reconstructed signal quality, when trying different values for M.
For results in the study, see the report.

The reconstruction will be done in MatLab (see reconstruct-file).
