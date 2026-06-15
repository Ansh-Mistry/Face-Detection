# Real Time Face Detection 
I have made a face detection app using OpenCV in C++.

## ✨ Features
* **Real-Time 1080p Processing:** Optimized to run smoothly on high-resolution webcam feeds without frame-rate drops.
* **Dynamic Downscaling Optimization:** Implements a scaling technique to process face-detection math at a smaller resolution (50% scale) while drawing the bounding boxes on the original 1080p feed. This eliminates the standard Haar Cascade CPU bottleneck.
* **Robust Error Handling:** Built-in failsafes prevent common OpenCV `abort()` crashes caused by missing XML models or dropped webcam frames.
* **Hardware Adaptable:** Easy to tweak the `scale` and `scaleFactor` parameters in the code to run smoothly on both high-end PCs and lower-power laptops.


## 🛠️ Prerequisites & Installation

### 1. Prerequisites
To build and run this project, you will need the following installed on your Windows machine:
* **Operating System:** Windows
* **C++ Compiler:** MSVC (via Visual Studio) or MinGW
* **OpenCV:** (v3.x or v4.x) installed and configured on your system.
* **CMake:** Installed on your system to handle the build process.
* **IDE (Optional but Recommended):** Visual Studio Code with the "CMake Tools" and "C/C++" extensions.

### 2. Installation
First, clone the repository to your local machine and navigate into the project folder:
```bash
git clone [https://github.com/Ansh-Mistry/Face-Detection.git](https://github.com/Ansh-Mistry/Face-Detection.git)

cd Face-Detection
```

### 3. Building & Running the Project

This project uses a dedicated build folder to keep the compiled files separate from the source code. You must be inside the build folder to compile and run the application.

#### Option A: Using Visual Studio Code (Recommended)

* Open the cloned `Face-Detection` folder in VS Code.

* Allow the CMake Tools extension to configure the project automatically.

* On the bottom blue status bar in VS Code, click the "Build" button.

* Once the build completes, click the triangular "Play/Run" button on the bottom bar to start the webcam.

#### Option B: Using the Command Line

Option B: Using the Command Line
Create a build directory and navigate into it:

```bash
mkdir build
cd build
```

* Generate the build files:
Compile the code using CMake (Ensure you are still in the build folder):

```bash
"C:\Program Files\CMake\bin\cmake.exe" --build . --config Debug
```

4. Running the Application
Once compiled via the command line, run the executable directly from the build folder:
```bash
Debug\FaceDetect.exe
```


## 🧠 Under the Hood: How it Works

This project does not just rely on a black-box AI; it uses classic Computer Vision techniques via OpenCV's Haar Cascade Classifier. Here is a breakdown of the underlying mechanics:

* **The Pre-trained Model:** The `haarcascade_frontalface_default.xml` file is not a script, but a pre-trained machine learning model. It contains a massive dataset of mathematical patterns representing both positive images (human faces) and negative images (non-faces).
* **Haar Features:** Instead of analyzing complex shapes, the algorithm converts the live video feed to grayscale and scans for "Haar Features." These are simple, rectangular patterns of light and dark pixels that exploit natural human facial contrast (for example, the area around the eyes is universally darker than the cheeks).
* **The Cascade System:** Scanning thousands of mathematical features across a high-resolution frame would normally severely drop the frame rate. To achieve real-time speed, the algorithm uses a "Cascade of Classifiers." It applies a few rapid, simple visual tests first, immediately discarding areas of the frame without faces. The heavy, complex calculations are reserved strictly for regions that pass the initial tests.
* **Performance Optimization:** By downscaling the grayscale frame before applying the `detectMultiScale` function, the CPU workload is drastically reduced. The resulting coordinates are then mathematically scaled back up to draw the bounding boxes accurately onto the live 1080p color feed without any lag.
