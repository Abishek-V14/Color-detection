import serial
import pygame
import os

def play_audio(file_path):
    pygame.mixer.init()
    pygame.mixer.music.load(file_path)
    pygame.mixer.music.play()


serial_port = 'COM7'  # Replace with your Arduino's serial port
baud_rate = 9600

ser = serial.Serial(serial_port, baud_rate)
script_dir = os.path.dirname(os.path.abspath(__file__))

while True:

    line = ser.readline().decode('utf-8', 'ignore').strip()

    print(line)

    if line == "white color":
        audio_file = os.path.join(script_dir, "White.mp3")
        play_audio(audio_file)
    elif line == "black color":
        audio_file = os.path.join(script_dir, "Black.mp3")
        play_audio(audio_file)
    elif line == "grey color":
        audio_file = os.path.join(script_dir, "Grey.mp3")
        play_audio(audio_file)
    elif line == "blue color":
        audio_file = os.path.join(script_dir, "Blue.mp3")
        play_audio(audio_file)
    elif line == "light blue color":
        audio_file = os.path.join(script_dir, "light Blue.mp3")
        play_audio(audio_file)
    elif line == "dark blue color":
        audio_file = os.path.join(script_dir, "Dark Blue.mp3")
        play_audio(audio_file)
    elif line == "brown color":
        audio_file = os.path.join(script_dir, "Brown.mp3")
        play_audio(audio_file)
    elif line == "green color":
        audio_file = os.path.join(script_dir, "Green.mp3")
        play_audio(audio_file)
    elif line == "light green color":
        audio_file = os.path.join(script_dir, "Light green.mp3")
        play_audio(audio_file)
    elif line == "dark green color":
        audio_file = os.path.join(script_dir, "Dark green.mp3")
        play_audio(audio_file)
    elif line == "maroon color":
        audio_file = os.path.join(script_dir, "Maroon.mp3")
        play_audio(audio_file)
    elif line == "orange color":
        audio_file = os.path.join(script_dir, "Orange.mp3")
        play_audio(audio_file)
    elif line == "pink color":
        audio_file = os.path.join(script_dir, "Pink.mp3")
        play_audio(audio_file)
    elif line == "Red color":
        audio_file = os.path.join(script_dir, "Red.mp3")
        play_audio(audio_file)
    elif line == "violet color":
        audio_file = os.path.join(script_dir, "Violet.mp3")
        play_audio(audio_file)
    elif line == "Yellow color":
        audio_file = os.path.join(script_dir, "Yellow.mp3")
        play_audio(audio_file)
    elif line == "looks like blue color":
        audio_file = os.path.join(script_dir, "Looks like blue color.mp3")
        play_audio(audio_file)
    elif line == "looks like Green color":
        audio_file = os.path.join(script_dir, "Looks like green color.mp3")
        play_audio(audio_file)
    elif line == "looks like Pink color":
        audio_file = os.path.join(script_dir, "Looks like pink color.mp3")
        play_audio(audio_file)
    elif line == "looks like Red color":
        audio_file = os.path.join(script_dir, "Looks like red color.mp3")
        play_audio(audio_file)