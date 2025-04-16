
from flask import Flask, render_template, request
import subprocess
import os
import signal

app = Flask(__name__)
detection_process = None                                                                                 

@app.route('/')
def index():
    return render_template('index.html')



@app.route('/start_detection', methods=['POST'])
def start_detection():
    global detection_process
    if detection_process is None:
        detection_process = subprocess.Popen(['python', 'C:/Users/himan/Desktop/sign_lan/yolov5/detect.py', 
                                              '--weights', 'C:/Users/himan/Desktop/sign_lan/yolov5/runs/train/yolov5s_results2/weights/best.pt', 
                                              '--img', '416', '--conf', '0.5', '--source', '0'])
    return render_template('index.html', message='Detection started')

@app.route('/stop_app', methods=['POST'])
def stop_app():
    global detection_process
    if detection_process is not None:
        detection_process.terminate()
        detection_process.wait()
        detection_process = None
    return render_template('index.html', message='Detection stopped')




if __name__ == '__main__':
    app.run(debug=True)