from django.shortcuts import render
from django.http import HttpResponse

#importando las librerias para el teclado
from pynput.keyboard import Key, Controller


def play(request):
	key = Controller()

	key.press(Key.media_play_pause)
	key.release(Key.media_play_pause)
	return HttpResponse('1')

#siguiente cancion
def next(request):
	key = Controller()

	key.press(Key.media_next)
	key.release(Key.media_next)

	return HttpResponse('1')


#cancion anterior
def previous(request):
	key = Controller()
	key.press(Key.media_previous)
	#se debe poner el release por que si no se presiona indefinidamente
	key.release(Key.media_previous)
	return HttpResponse('1')
