**NEURAL NETWORK FROM SCRATCH USING C++ FOR MNIST DATASET**

Today we have self-driving cars.
But still, we prefer to learn driving.

Why?
Because it feels amazing to drive on our own —
we feel the journey, not just the destination.
When automatic cars drive, we simply arrive.
When we drive, we enjoy every moment between the start and the destination. 🚗✨

The same applies to machine learning.

Using TensorFlow or PyTorch is like being on autopilot —
you’ll reach the destination, but you’ll miss the experience.

I wanted to drive it myself:

to feel the equations,

to struggle with gradients,

to fix my own mistakes,

and to enjoy the journey of building intelligence line by line.

Instead of saying “it works because I used TensorFlow/PyTorch”, I asked:
**HOW does it work?
WHY does it work?**

So I decided to write everything from scratch.

**WHATS INSIDE TH CODE**

📂 Matrix.h / Matrix.cpp
    Custom matrix class with core operations — multiplication, addition, subtraction, transpose, etc.

📂 Layer.h / Layer.cpp
    Implementation of neural network layers — weights, bias, outputs, and connections.

📂 Algorithms.h / Algorithms.cpp
    Activation functions and their derivatives — ReLU, Softmax, Sigmoid, etc.

📂 Neural_network.h / Neural_network.cpp
    The neural network engine — forward pass, backpropagation, and training logic.

📂 Model_weights.h / Model_weights.cpp
    Weight saving/loading functionality — so trained brains can be reused later.

📂 DataSet.h / DataSet.cpp
    Dataset loader — written for MNIST, including input normalization.

📂 Main.cpp
    The entry point — training, evaluation, and testing workflow.
