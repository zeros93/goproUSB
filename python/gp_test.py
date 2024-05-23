#

import requests

base_url = "http://172.27.199.51:8080"

# Configure Turbo Transfer
print("Configure Turbo Transfer")
url = base_url + "/gopro/media/turbo_transfer"
querystring = {"p": "0"}
response = requests.request("GET", url, params=querystring)
print(response)

# Enable Wired camera control over USB
print("Enable Wired camera control over USB")
url = base_url + "/gopro/camera/control/wired_usb"
querystring = {"p": "1"}
#response = requests.request("GET", url, params=querystring)
#print(response)

# Keep Alive
print("Keep Alive")
url = base_url + "/gopro/camera/keep_alive"
response = requests.request("GET", url)
print(response)

# Set Camera Control Status
print("Set Camera Control Status")
url = base_url + "/gopro/camera/control/set_ui_controller"
querystring = {"p": "1"}
#response = requests.request("GET", url, params=querystring)
#print(response)

# Set Date / Time
print("Set Date / Time")
url = base_url + "/gopro/camera/set_date_time"
querystring = {"date":"2024_05_23", "time":"14_20_13"}
#response = requests.request("GET", url, params=querystring)
#print(response)

# Set Digital Zoom
print("Set Digital Zoom")
url = base_url + "/gopro/camera/digital_zoom"
querystring = {"percent":50}
#response = requests.request("GET", url, params=querystring)
#print(response)

# Set Shutter
print("Set Shutter")
url = base_url + "/gopro/camera/shutter/start"
#response = requests.request("GET", url)
#print(response)

url = base_url + "/gopro/camera/shutter/stop"
#response = requests.request("GET", url)
#print(response)

# Delete Grouped Media Item
print("Delete Grouped Media Item")
url = base_url + "/gp/gpControl/command/storage/delete/group?p=100GOPRO/GH010002.MP4"
#response = requests.request("GET", url)
#print(response)

# Delete Single Media Item
print("Delete Single Media Item")
url = base_url + "/gopro/media/delete/file?path=100GOPRO/GOPR0014.JPG"
#response = requests.request("GET", url)
#print(response)

# Get Media File GPMF
print("Get Media File GPMF")
url = base_url + "/gopro/media/gpmf?path=100GOPRO/GOPR0015.JPG"
response = requests.request("GET", url)
print(response.text)

# Get Media File Info
print("Get Media File Info")
url = base_url + "/gopro/media/info?path=100GOPRO/GOPR0015.JPG"
response = requests.request("GET", url)
print(response.text)

# Get Media List
print("Get Media List")
url = base_url + "/gopro/media/list"
response = requests.request("GET", url)
#print(response.text)

# Get Available Presets
print("Get Available Presets")
url = base_url + "/gopro/camera/presets/get"
response = requests.request("GET", url)
print(response.text)

# Get Camera State
print("Get Camera State")
url = base_url + "/gopro/camera/state"
response = requests.request("GET", url)
print(response.text)

# Get Date / Time
print("Get Date / Time")
url = base_url + "/gopro/camera/get_date_time"
response = requests.request("GET", url)
print(response.text)

# Get Hardware Info
print("Get Hardware Info")
url = base_url + "/gopro/camera/info"
response = requests.request("GET", url)
print(response.text)

# Get Open GoPro Version
print("Get Open GoPro Version")
url = base_url + "/gopro/version"
response = requests.request("GET", url)
print(response.text)

# Auto Power Down (59)
print("Auto Power Down (59)")
url = base_url + "/gopro/camera/setting?setting=59&option=0"
response = requests.request("GET", url)
print(response)

# GPS (83)
print("GPS (83)")
url = base_url + "/gopro/camera/setting?setting=83&option=0"
response = requests.request("GET", url)
print(response)

# HindSight (167)
print("HindSight (167)")
url = base_url + "/gopro/camera/setting?setting=167&option=2"
response = requests.request("GET", url)
print(response)

# Max Lens (162)
print("Max Lens (162)")
url = base_url + "/gopro/camera/setting?setting=162&option=0"
response = requests.request("GET", url)
print(response)

# Setup Anti-Flicker (134)
print("Setup Anti-Flicker (134)")
url = base_url + "/gopro/camera/setting?setting=134&option=2"
response = requests.request("GET", url)
print(response)

# Video Resolution (2)
print("Video Resolution (2)")
url = base_url + "/gopro/camera/setting?setting=2&option=1"
response = requests.request("GET", url)
print(response)

# Enter Webcam Preview
print("Enter Webcam Preview")
url = base_url + "/gopro/webcam/preview"
response = requests.request("GET", url)
print(response)

# Get Webcam Status
print("Get Webcam Status")
url = base_url + "/gopro/webcam/status"
response = requests.request("GET", url)
print(response.text)

# Get Webcam Version
print("Get Webcam Version")
url = base_url + "/gopro/webcam/version"
response = requests.request("GET", url)
print(response.text)

# Exit Webcam Mode
print("Exit Webcam Mode")
url = base_url + "/gopro/webcam/exit"
response = requests.request("GET", url)
print(response)
