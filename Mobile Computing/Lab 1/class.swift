struct Resolution {
	var height = 0
	var width = 0
}

class VideoMode{
	var resolution = Resolution()
	var interlaced = false
	var frameRate = 0.0
	var name: String?
	
}


var video = VideoMode()
video.frameRate = 1.0
print(video.frameRate)



