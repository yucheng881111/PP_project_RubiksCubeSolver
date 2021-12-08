from random import randint
import tkinter as tk
import copy, webbrowser, os
from tkinter import *

#This is the Cube Solver
#This version contains a GUI
#Last Edited on: 12/5/2014
#Written by: Lucas Liberacki & Tom Brannan


#globals
moves_list = []
last_scramble = []
f2l_list = []
step_moves_list = []
solution_length = 0
num_to_move = ['','l','li','m','mi','ri','r','ui','u','dw di','dwi d','d','di']
cnt = 0

#creates a 3d list representing a solved cube
def make_cube():
    global step_moves_list, f2l_list, moves_list
    step_moves_list = [0,0,0,0]
    f2l_list = []
    moves_list = []
    return [   [['W', 'W', 'W'],
                ['W', 'W', 'W'],
                ['W', 'W', 'W']], #Up/white
               
               [['G', 'G', 'G'],
                ['G', 'G', 'G'],
                ['G', 'G', 'G']], #front/green
               
               [['R', 'R', 'R'],
                ['R', 'R', 'R'],
                ['R', 'R', 'R']], #right/red
               
               [['O', 'O', 'O'],
                ['O', 'O', 'O'],
                ['O', 'O', 'O']], #left/orange
               
               [['Y', 'Y', 'Y'],
                ['Y', 'Y', 'Y'],
                ['Y', 'Y', 'Y']], #down/yellow
               
               [['B', 'B', 'B'],
                ['B', 'B', 'B'],
                ['B', 'B', 'B']]] #back/blue

a = make_cube()

#prints a string representation of the cube to the interpreter
def print_cube():
    print('\t\t'+str(a[5][0])+'\n\t\t'+str(a[5][1])+'\n\t\t'+str(a[5][2]))   
    print(str(a[3][0])+' '+str(a[0][0])+' '+str(a[2][0]))
    print(str(a[3][1])+' '+str(a[0][1])+' '+str(a[2][1]))   
    print(str(a[3][2])+' '+str(a[0][2])+' '+str(a[2][2]))
    print('\t\t'+str(a[1][0])+'\n\t\t'+str(a[1][1])+'\n\t\t'+str(a[1][2]))
    print('\t\t'+str(a[4][0])+'\n\t\t'+str(a[4][1])+'\n\t\t'+str(a[4][2]))

#simplifies the list of moves and returns a string representation of the moves
def get_moves():
    simplify_moves()
    s = ""
    for i in moves_list:
        s += str(i) + " "
    s = str.replace(s, "i", "'")[:-1] 
    return s

#returns a string representation of the last scramble
def get_scramble():
    s = ""
    for i in last_scramble:
        s += str(i) + " "
    s = str.replace(s, "i", "'")[:-1]
    return s

#helper function: returns True if all elements in a set are equal
def all_same(items):
    return all(x == items[0] for x in items)

#Transforms a given move into the corresponding move after a Y-rotation
def yTransform(move):
    if move[0] in ["U", "D"]:
        return move
    if move[0] == "F":
        return "R" + move[1:]
    if move[0] == "R":
        return "B" + move[1:]
    if move[0] == "B":
        return "L" + move[1:]
    if move[0] == "L":
        return "F" + move[1:]
    raise Exception("Invalid move to yTransform: " + move)

#modifies the global moves list by removing redundancies
def simplify_moves():
    global moves_list, solution_length
    new_list = []
    prev_move = ""
    yCount = 0
    for move in moves_list:
        if move == "Y":
            yCount += 1
            yCount %= 4
            continue
        if move == "Yi":
            yCount += 3
            yCount %= 4
            continue
        if move == "Y2":
            yCount += 2
            yCount %= 4
            continue
        if yCount > 0:
            for i in range(yCount):
                move = yTransform(move)
        if prev_move == "" or prev_move == '':
            prev_move = move
            new_list.append(move)
            continue
        if move[0] == prev_move[0]:
            if len(move) == 1:
                if len(prev_move) <= 1:
                    del new_list[-1]
                    mv = move[0] + "2"
                    new_list.append(mv)
                    prev_move = mv
                    continue
                if prev_move[1] == "i":
                    del new_list[-1]
                    prev_move = new_list[-1] if len(new_list) > 0 else ""
                    continue
                if prev_move[1] == "2":
                    del new_list[-1]
                    mv = move[0] + "i"
                    new_list.append(mv)
                    prev_move = mv
                    continue
            if move[1] == "i":
                if len(prev_move) == 1:
                    del new_list[-1]
                    prev_move = new_list[-1] if len(new_list) > 0 else ""
                    continue
                if prev_move[1] == "i":
                    del new_list[-1]
                    mv = move[0] + "2"
                    new_list.append(mv)
                    prev_move = mv
                    continue
                if prev_move[1] == "2":
                    del new_list[-1]
                    mv = move[0]
                    new_list.append(mv)
                    prev_move = mv
                    continue
            if move[1] == "2":
                if len(prev_move) == 1:
                    del new_list[-1]
                    mv = move[0] + "i"
                    new_list.append(mv)
                    prev_move = mv
                    continue
                if prev_move[1] == "i":
                    del new_list[-1]
                    mv = move[0]
                    new_list.append(mv)
                    prev_move = mv
                    continue
                if prev_move[1] == "2":
                    del new_list[-1]
                    prev_move = new_list[-1] if len(new_list) > 0 else ""
                    continue
        new_list.append(move)
        prev_move = move
    solution_length = len(new_list)
    moves_list = new_list

#sets up the cube to perform a move by rotating that face to the top
def setup(face):
    face = str.lower(face)
    if face == "f":
        move("X")
    elif face == "r":
        move("Zi")
    elif face == "l":
        move("Z")
    elif face == "d":
        move("X2")
    elif face == "b":
        move("Xi")
    else:
        raise Exception("Invalid setup; face: " + face)

#performs the inverse of setup to restore the cube's previous orientation
def undo(face):
    face = str.lower(face)
    if face == "f":
        move("Xi")
    elif face == "r":
        move("Z")
    elif face == "l":
        move("Zi")
    elif face == "d":
        move("X2")
    elif face == "b":
        move("X")
    else:
        raise Exception("Invalid undo; face: " + face)

#Tokenizes a string of moves 	
def m(s):
    s = str.replace(s, "'", "i")
    k = s.split(' ')
    global moves_list, solution_length
    solution_length += len(k)
    for word in k:
        moves_list.append(word)
        move(word)

#performs a move by setting up, performing U moves, and undoing the setup
def move(mv):
    mv = str.lower(mv)
    if mv == "u":
        U()
    elif mv == "u2":
        move("U"); move("U");
    elif mv == "ui":
        move("U"); move("U"); move("U");
    elif mv == "f":
        setup("F"); U(); undo("F");
    elif mv == "f2":
        move("F"); move("F");
    elif mv == "fi":
        move("F"); move("F"); move("F");
    elif mv == "r":
        setup("R"); U(); undo("R");
    elif mv == "r2":
        move("R"); move("R");
    elif mv == "ri":
        move("R"); move("R"); move("R");
    elif mv == "l":
        setup("L"); U(); undo("L");
    elif mv == "l2":
        move("L"); move("L");
    elif mv == "li":
        move("L"); move("L"); move("L");
    elif mv == "b":
        setup("B"); U(); undo("B");
    elif mv == "b2":
        move("B"); move("B");
    elif mv == "bi":
        move("B"); move("B"); move("B");
    elif mv == "d":
        setup("D"); U(); undo("D");
    elif mv == "d2":
        move("D"); move("D");
    elif mv == "di":
        move("D"); move("D"); move("D");
    elif mv == "x":
        rotate("X")
    elif mv == "x2":
        move("X"); move("X");
    elif mv == "xi":
        move("X"); move("X"); move("X");
    elif mv == "y":
        rotate("Y")
    elif mv == "y2":
        move("Y"); move("Y");
    elif mv == "yi":
        move("Y"); move("Y"); move("Y");
    elif mv == "z":
        rotate("Z")
    elif mv == "z2":
        move("Z"); move("Z");
    elif mv == "zi":
        move("Z"); move("Z"); move("Z");
    elif mv == "uw":
        move("D"); move("Y");
    elif mv == "uw2":
        move("UW"); move("UW");
    elif mv == "uwi":
        move("UW"); move("UW"); move("UW");
    elif mv == "m":
        move("Li"); move("R"); move("Xi");
    elif mv == "mi":
        move("M"); move("M"); move("M");
    elif mv == "m2":
        move("M"); move("M");
    elif mv == "rw":
        move("L"); move("X");
    elif mv == "rwi":
        move("RW"); move("RW"); move("RW");
    elif mv == "rw2":
        move("RW"); move("RW");
    elif mv == "fw":
        move("Bi"); move("Z");
    elif mv == "fwi":
        move("FW"); move("FW"); move("FW");
    elif mv == "fw2":
        move("FW"); move("FW");
    elif mv == "lw":
        move("R"); move("Xi");
    elif mv == "lwi":
        move("LW"); move("LW"); move("LW");
    elif mv == "lw2":
        move("LW"); move("LW");
    elif mv == "bw":
        move("F"); move("Zi");
    elif mv == "bwi":
        move("BW"); move("BW"); move("BW");
    elif mv == "bw2":
        move("BW"); move("BW");
    elif mv == "dw":
        move("U"); move("Yi");
    elif mv == "dwi":
        move("DW"); move("DW"); move("DW");
    elif mv == "dw2":
        move("DW"); move("DW");
    else:
        raise Exception("Invalid Move: " + str(mv))

#rotates the entire cube along a particular axis
def rotate(axis):
    axis = str.lower(axis)
    if axis == 'x': #R
        temp = a[0]
        a[0] = a[1]
        a[1] = a[4]
        a[4] = a[5]
        a[5] = temp
        rotate_face_counterclockwise("L")
        rotate_face_clockwise("R")
    elif axis == 'y': #U
        temp = a[1]
        a[1] = a[2]
        a[2] = a[5]
        a[5] = a[3]
        a[3] = temp
        #after swaps,
        rotate_face_clockwise("L")
        rotate_face_clockwise("F")
        rotate_face_clockwise("R")
        rotate_face_clockwise("B")
        rotate_face_clockwise("U")
        rotate_face_counterclockwise("D")
    elif axis == 'z': #F
        temp = a[0]
        a[0] = a[3]
        a[3] = a[4]
        a[4] = a[2]
        a[2] = temp
        rotate_face_clockwise("L"); rotate_face_clockwise("L");
        rotate_face_clockwise("D"); rotate_face_clockwise("D");
        rotate_face_clockwise("F")
        rotate_face_counterclockwise("B")
    else:
        raise Exception("Invalid rotation: " + axis)

#performs a U move
def U():
    #rotate U face
    temp = a[0][0][0]
    a[0][0][0] = a[0][2][0]
    a[0][2][0] = a[0][2][2]
    a[0][2][2] = a[0][0][2]
    a[0][0][2] = temp
    temp = a[0][0][1]
    a[0][0][1] = a[0][1][0]
    a[0][1][0] = a[0][2][1]
    a[0][2][1] = a[0][1][2]
    a[0][1][2] = temp

    #rotate others
    temp = a[5][2][0]
    a[5][2][0] = a[3][2][2]
    a[3][2][2] = a[1][0][2]
    a[1][0][2] = a[2][0][0]
    a[2][0][0] = temp
    temp = a[5][2][1]
    a[5][2][1] = a[3][1][2]
    a[3][1][2] = a[1][0][1]
    a[1][0][1] = a[2][1][0]
    a[2][1][0] = temp
    temp = a[5][2][2]
    a[5][2][2] = a[3][0][2]
    a[3][0][2] = a[1][0][0]
    a[1][0][0] = a[2][2][0]
    a[2][2][0] = temp

#Rotates a particular face counter-clockwise
def rotate_face_counterclockwise(face):
    rotate_face_clockwise(face)
    rotate_face_clockwise(face)
    rotate_face_clockwise(face)

#Rotates a particular face clockwise
def rotate_face_clockwise(face):
    f_id = -1
    face = str.lower(face)
    if face == "u":
        f_id = 0
    elif face == "f":
        f_id = 1
    elif face == "r":
        f_id = 2
    elif face == "l":
        f_id = 3
    elif face == "d":
        f_id = 4
    elif face == "b":
        f_id = 5
    else:
        raise Exception("Invalid face: " + face)
    temp = a[f_id][0][0]
    a[f_id][0][0] = a[f_id][2][0]
    a[f_id][2][0] = a[f_id][2][2]
    a[f_id][2][2] = a[f_id][0][2]
    a[f_id][0][2] = temp
    temp = a[f_id][0][1]
    a[f_id][0][1] = a[f_id][1][0]
    a[f_id][1][0] = a[f_id][2][1]
    a[f_id][2][1] = a[f_id][1][2]
    a[f_id][1][2] = temp


    
######################################################################################################
#Below is all the work for the GUI portion of the Cube Solver
######################################################################################################
#These are all the globals used for the GUI
root = None
frame = None
canvas = None
ScrambleLabel = None
SolutionLabel = None
SolutionNumberLabel = None
isTransparent = None
F2LNumberLabel = None
CrossNumberLabel = None
OLLNumberLabel = None
PLLNumberLabel = None
SimulateBestLabel = None
SimulateWorstLabel = None

#cubePoints are all of the x and y coordinates for the polygons used for the tiles
def cubePoints():
    #h and w may be changed to allow the cube to be moved around the screen
    h = 175
    w = 115
    #right face
    #layer 1
    r00p = [0+w, 0+h, 0+w, 50+h, 33+w, 30+h, 33+w, -20+h]
    r01p = [33+w, -20+h, 33+w, 30+h, 66+w, 10+h, 66+w, -40+h]
    r02p = [66+w, -40+h, 66+w, 10+h, 99+w, -10+h, 99+w, -60+h]
    #layer 2
    r10p = [0+w, 50+h, 0+w, 100+h, 33+w, 80+h, 33+w, 30+h]
    r11p = [33+w, 30+h, 33+w, 80+h, 66+w, 60+h, 66+w, 10+h]
    r12p = [66+w, 10+h, 66+w, 60+h, 99+w, 40+h, 99+w, -10+h]
    #layer 3
    r20p = [0+w, 100+h, 0+w, 150+h, 33+w, 130+h, 33+w, 80+h]
    r21p = [33+w, 80+h, 33+w, 130+h, 66+w, 110+h, 66+w, 60+h]
    r22p = [66+w, 60+h, 66+w, 110+h, 99+w, 90+h, 99+w, 40+h]
    #left face (left face will be front face, however called l face to distinguish between the left and right)
    #layer 1
    l00p = [-66+w, -40+h, -66+w, 10+h, -99+w, -10+h, -99+w, -60+h]
    l01p = [-33+w, -20+h, -33+w, 30+h, -66+w, 10+h, -66+w, -40+h]
    l02p = [0+w, 0+h, 0+w, 50+h, -33+w, 30+h, -33+w, -20+h]
    #layer 2
    l10p = [-66+w, 10+h, -66+w, 60+h, -99+w, 40+h, -99+w, -10+h]
    l11p = [-33+w, 30+h, -33+w, 80+h, -66+w, 60+h, -66+w, 10+h]
    l12p = [0+w, 50+h, 0+w, 100+h, -33+w, 80+h, -33+w, 30+h]
    #layer 3
    l20p = [-66+w, 60+h, -66+w, 110+h, -99+w, 90+h, -99+w, 40+h]
    l21p = [-33+w, 80+h, -33+w, 130+h, -66+w, 110+h, -66+w, 60+h]
    l22p = [0+w, 100+h, 0+w, 150+h, -33+w, 130+h, -33+w, 80+h]
    #up face
    #layer 1
    u00p = [0+w, -75+h, -33+w, -94+h, 0+w, -111+h, 33+w, -94+h]
    u01p = [36+w, -57+h, 0+w, -75+h, 33+w, -94+h, 69+w, -76+h]
    u02p = [66+w, -40+h, 36+w, -57+h, 69+w, -76+h, 99+w, -60+h]
    #layer 2
    u10p = [-33+w, -57+h, -66+w, -77+h, -33+w, -94+h, 0+w, -75+h]
    u11p = [0+w, -38+h, -33+w, -57+h, 0+w, -75+h, 36+w, -57+h]
    u12p = [33+w, -20+h, 0+w, -38+h, 36+w, -57+h, 66+w, -40+h]
    #layer 3
    u20p = [-66+w, -40+h, -99+w, -60+h, -66+w, -77+h, -33+w, -57+h]
    u21p = [-33+w, -20+h, -66+w, -40+h, -33+w, -57+h, 0+w, -38+h]
    u22p = [0+w, 0+h, -33+w, -20+h, 0+w, -38+h, 33+w, -20+h]

    dh = h + 200
    dw = w
    #d face
    #layer 1
    d00p = [0+dw, -75+dh, -33+dw, -94+dh, 0+dw, -111+dh, 33+dw, -94+dh]
    d01p = [36+dw, -57+dh, 0+dw, -75+dh, 33+dw, -94+dh, 69+dw, -76+dh]
    d02p = [66+dw, -40+dh, 36+dw, -57+dh, 69+dw, -76+dh, 99+dw, -60+dh]
    #layer 2
    d10p = [-33+dw, -57+dh, -66+dw, -77+dh, -33+dw, -94+dh, 0+dw, -75+dh]
    d11p = [0+dw, -38+dh, -33+dw, -57+dh, 0+dw, -75+dh, 36+dw, -57+dh]
    d12p = [33+dw, -20+dh, 0+dw, -38+dh, 36+dw, -57+dh, 66+dw, -40+dh]
    #layer 3
    d20p = [-66+dw, -40+dh, -99+dw, -60+dh, -66+dw, -77+dh, -33+dw, -57+dh]
    d21p = [-33+dw, -20+dh, -66+dw, -40+dh, -33+dw, -57+dh, 0+dw, -38+dh]
    d22p = [0+dw, 0+dh, -33+dw, -20+dh, 0+dw, -38+dh, 33+dw, -20+dh]
    
    return [    [[u00p, u01p, u02p],
                 [u10p, u11p, u12p],
                 [u20p, u21p, u22p]], #Upside

                [[l00p, l01p, l02p],
                 [l10p, l11p, l12p],
                 [l20p, l21p, l22p]], #front face (used l to denote the left showing face)

                [[r02p, r12p, r22p],
                 [r01p, r11p, r21p],
                 [r00p, r10p, r20p]], # right face (different than other faces because it is formatted differently)

                [[d20p, d21p, d22p],
                 [d10p, d11p, d12p],
                 [d00p, d01p, d02p]]] #downside

def clickCanvas(canvas):
    global isTransparent
    isTransparent = not isTransparent
    canvas.delete(ALL)
    drawCube()


#DrawCanvas will take the root and draw a new canvas, also returning it.
def drawCanvas(root):
    canvas=tk.Canvas(root, width=225, height=400, background='white')
    canvas.grid(row=0,column=0)
    canvas.bind("<Button-1>", lambda e: clickCanvas(canvas))
    return canvas

#Used to get the word for each color, used in drawCube(canvas()
def getColor(element):
    if element == 'B':
        return "#06F" #Nice shade of blue
    elif element == 'W':
        return "white"
    elif element == 'G':
        return "green"
    elif element == 'Y':
        return "yellow"
    elif element == 'O':
        return "orange"
    elif element == 'R':
        return "#D11"

#drawCube() will take the already created canvas and draw the cube with polygons whose points are defined in cubePoints()
def drawCube():
    global isTransparent, canvas
    pts = cubePoints()
    for j in range(3):
        for k in range(3):
            canvas.create_polygon(pts[3][j][k], fill=getColor(a[4][j][k]), outline="#000", width=2)
    for i in range(3):
        for j in range(3):
            for k in range(3):
                if isTransparent:
                    frontTiles = (i == 1) and ((j == 1 and k == 2) or (j == 2 and k == 2) or (j == 2 and k == 1))
                    rightTiles = (i == 2) and ((j == 1 and k == 2) or (j == 2 and k == 2) or (j == 2 and k == 1))
                    if  frontTiles or rightTiles:
                        canvas.create_polygon(pts[i][j][k], fill="", outline="#000", width=2)
                    else:
                        canvas.create_polygon(pts[i][j][k], fill=getColor(a[i][j][k]), outline="#000", width=2)
                else:
                    canvas.create_polygon(pts[i][j][k], fill=getColor(a[i][j][k]), outline="#000", width=2)



#GUImakeMove is used to make moves based on what is in the EntryBox. After clicking Draw, it will redraw the canvas with the updated cube
def GUImakeMove(move):
    global canvas
    if move.get() == "":
        return
    m(move.get())
    canvas.delete(ALL)
    drawCube()

y_rotated = False
a_before_y_rotate = []
#This is used for the rotation of the cube with buttons. It takes in either a Yi or Y move to be executed
def GUIyRotation(given):
    global canvas, y_rotated, a_before_y_rotate, a
    if y_rotated == False:
        y_rotated = True
        a_before_y_rotate = copy.deepcopy(a)

    if given == "Y" or given == "y":
        move('y')
    elif given == "Yi" or given == "Y'" or given == "yi" or given == "y'":
        move('yi')
    canvas.delete(ALL)
    drawCube()

def NextState():
    global cnt, canvas, y_rotated, a_before_y_rotate, a
    if y_rotated == True:
        a = a_before_y_rotate
        y_rotated = False

    s = num_to_move[solve_steps[cnt]]
    m(s)
    cnt += 1
    canvas.delete(ALL)
    drawCube()

def PrevState():
    global cnt, canvas, y_rotated, a_before_y_rotate, a
    if y_rotated == True:
        a = a_before_y_rotate
        y_rotated = False

    cnt -= 1
    k = solve_steps[cnt]
    if k % 2 == 1:
        k += 1
    else:
        k -= 1

    s = num_to_move[k]
    m(s)
    canvas.delete(ALL)
    drawCube()


#GUI is the main GUI that will be created, it calls GUIy which actually does all the work for the GUI
def GUI():
    global root
    root = tk.Tk()
    root.geometry("550x550+50+50") #size of the starting frame
    root.wm_title("Cube Solver")
    root.resizable(True, True) #Only allows the height to be resized, not the width
    GUIy()
    root.mainloop()
 
#GUIy, after the GUI itself is created with GUI(), this will create all the buttons, labels, etc.. and add them into a frame. This is the behind the
#scenes work for the GUI itself.
def GUIy():
    global root, canvas, ScrambleLabel, SolutionLabel, SolutionNumberLabel, frame,isTransparent
    global PLLNumberLabel,F2LNumberLabel, CrossNumberLabel,OLLNumberLabel, SimulateBestLabel, SimulateWorstLabel
    
    isTransparent = False
    canvas = drawCanvas(root)
    drawCube()

    #locals
    move = StringVar(value="")
    scram = StringVar(value="Enter Scramble Here")
    simNum = IntVar()#Simulation Number
    
    #Frame for controls
    frame = Frame(root)
    frame.grid(row=0,column=1, sticky="n")

    #Frame for cube rotations
    Rframe = Frame(root)
    Rframe.grid(row=0, column=0, sticky = "n")

    #row 1 - welcome label and new cube button
    #Welcome = Label(frame, text = "Welcome to the Cube Solver").grid(row=1,column=0)
    #NewCubeButton = Button(frame,text="New Cube", command = lambda: GUInewCube())
    #NewCubeButton.grid(row=1, column=1)
    #row 2 - label to tell you to enter a move for execution
    EnterMove = Label(frame, text ="Enter move(s):").grid(row=2,column=0)
    #row 3 - Has entry for custom moves as well as button to execute them
    MoveEntry = Entry(frame, textvariable=move).grid(row = 3, column=0)
    DrawCubeButton=Button(frame,text="Execute", command = lambda: GUImakeMove(move)).grid(row = 3,column = 1, sticky="w")
    #row 4 - The label that will print out the current scramble after generation
    #ScrambleLabel = Label(frame, text="Scramble will be displayed here",wraplength=180, justify=CENTER, height = 2)
    #ScrambleLabel.grid(row=4,column=0, columnspan=2)
    #row 5 - The scramble button to generate new scramble and copy scramble to clipboard
    #ScrambleButton = Button(frame, text="Scramble",bg="lightgreen", command = lambda: GUIScramble()).grid(row = 5, column = 0)
    #CopyScrambleButton = Button(frame, text="Copy Scramble",bg="#EF9", command = lambda: GUItoClipboard(get_scramble())).grid(row = 5, column = 1)
    #row 6 - entry for custom scramble and button to apply custom scramble to cube
    #CustomScramEntry = Entry(frame, textvariable=scram)
    #CustomScramEntry.grid(row=6,column=0,sticky="w")
    #CustomScramButton = Button(frame,text="Custom Scramble",bg="lightgreen", command = lambda: GUIcustomScramble(scram))
    #CustomScramButton.grid(row=6,column=1)
    #row 7 - Slow solve (using timer to do it slowly), instant solve(quick and instant solution), copy solution to clipboard buttons
    #SolveTimerButton = Button(frame, text="Slow Solve", bg="#D53", command = lambda: GUIautomateSolve()).grid(row=7, column=0, sticky="w", pady=5)
    #SolveButton = Button(frame, text="Solve Cube",bg="#D53",command = lambda: GUISolve()).grid(row = 7, column = 0) #sticky="e" if using timer button as well
    #CopyScrambleButton = Button(frame, text="Copy Solution",bg="#EF9", command = lambda: GUItoClipboard(get_moves())).grid(row = 7, column = 1)
    

    

    NextButton = Button(frame, text="Prev",bg="lightblue", command = lambda: PrevState())
    NextButton.grid(row=8, column=0)
    PrevButton = Button(frame, text="Next",bg="lightblue", command = lambda: NextState())
    PrevButton.grid(row=8, column=0, sticky="e")

    #OLLButton = Button(frame, text="OLL",bg="lightblue", command = lambda: GUIsetSolve("OLL"))
    #OLLButton.grid(row=8, column=1, sticky = "w")
    #PLLButton = Button(frame, text="PLL",bg="lightblue", command = lambda: GUIsetSolve("PLL"))
    #PLLButton.grid(row=8, column=1, sticky = "e", padx=30)


    #row 9 - the label that contains the solution that will be generated
    #SolutionLabel = Label(frame, text="Solution will be displayed here", wraplength = 250, justify=CENTER, height = 8)
    #SolutionLabel.grid(row=9, column=0, columnspan=2)
    #row 10 - Labels for number of moves needed to solve 
    #SolutionNumberInfoLabel = Label(frame, text="Total number of moves used:")
    #SolutionNumberInfoLabel.grid(row=10, column=0,sticky="e")
    #SolutionNumberLabel = Label(frame, text="0")
    #SolutionNumberLabel.grid(row=10, column=1,sticky="w")
    #row 11, 12, 13, 14 - Labels for number of moves for the different steps
    #CrossInfoLabel = Label(frame, text="Moves needed for Cross:")
    #CrossInfoLabel.grid(row=11,column=0,sticky="e")
    #CrossNumberLabel = Label(frame,text="0")
    #CrossNumberLabel.grid(row=11, column=1,sticky="w")
    #F2LInfoLabel = Label(frame, text= "Moves needed for F2L:")
    #F2LInfoLabel.grid(row = 12, column=0,sticky="e")
    #F2LNumberLabel = Label(frame,text="0")
    #F2LNumberLabel.grid(row=12, column=1,sticky="w")
    #OLLInfoLabel = Label(frame,text="Moves needed for OLL:")
    #OLLInfoLabel.grid(row=13, column=0,sticky="e")
    #OLLNumberLabel = Label(frame,text="0")
    #OLLNumberLabel.grid(row=13, column=1,sticky="w")
    #PLLInfoLabel = Label(frame,text="Moves needed for PLL:")
    #PLLInfoLabel.grid(row=14, column=0,sticky="e")
    #PLLNumberLabel = Label(frame, text="0")
    #PLLNumberLabel.grid(row=14, column=1,sticky="w")
    #row 15 - Exporting to alg.cubing.net
    #ExportSolveButton = Button(frame, text="Export to alg.cubing.net", command = lambda: GUIexportSolve())
    #ExportSolveButton.grid(row=15,column=0)
    #row 16 - Simulations for Best solve
    #SimulateEntry = Entry(frame, textvariable = simNum)
    #SimulateEntry.grid(row=16, column=0)
    #SimulateButton = Button(frame, text="Start Simulations", command = lambda: GUISimulation(simNum))
    #SimulateButton.grid(row=16,column=1)
    #row 17 - Which best was found
    #SimulateBestInfo = Label(frame, text="Best Simulation: ")
    #SimulateBestInfo.grid(row=17,column=0)
    #SimulateBestLabel = Label(frame,text="")
    #SimulateBestLabel.grid(row=17,column=1,sticky="w")
    #row 18 Which worst was found
    #SimulateWorstInfo = Label(frame, text="Worst Simulation: ")
    #SimulateWorstInfo.grid(row=18, column=0)
    #SimulateWorstLabel = Label(frame,text="")
    #SimulateWorstLabel.grid(row=18, column=1)
    
    #In Rframe, buttons for rotation
    RotationLabel = Label(Rframe,text="Use the buttons below to rotate the cube").grid(row=0,column=0, columnspan=2)
    YrotationButton = Button(Rframe, text="<---- Y", command = lambda: GUIyRotation("Y"))
    YrotationButton.grid(row=1, column=0)
    YirotationButton = Button(Rframe, text="Y' ---->", command = lambda: GUIyRotation("Yi"))
    YirotationButton.grid(row=1, column=1)
      

A = []
with open('cube_states.txt', 'r') as f:
    A = f.readlines()

A = [line.strip('\n') for line in A]

steps = ""
solve_steps = []
for i in range(len(A)):
    if i % 2 == 1:
        steps += (num_to_move[int(A[i])] + ' ')

        if int(A[i]) % 2 == 1:
            solve_steps.append(int(A[i]) + 1)
        else:
            solve_steps.append(int(A[i]) - 1)


m(steps.strip(' '))

solve_steps.reverse()
solve_steps_str = ""
for num in solve_steps:
    solve_steps_str += (num_to_move[num] + ' ')

solve_steps_str = solve_steps_str.strip(' ')

GUI()







