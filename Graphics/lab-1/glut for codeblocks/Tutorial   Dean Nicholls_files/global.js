window.fbAsyncInit = function() {
	FB.init({
	        appId: '<?php echo Config::$FB_APP_ID; ?>', 
	        status: true, 
	        cookie: true, 
	        xfbml: true, 
	        frictionlessRequests: true,
	        oauth: true
	});
	/* All the events registered */
	FB.Event.subscribe('auth.login', function(response) {
	// do something with response
	        //alert('logged in');
	});
	FB.Event.subscribe('auth.logout', function(response) {
	// do something with response
	        //alert('logged out');
	});
	FB.getLoginStatus(function(response) {
	        if (response.session) {
	                // logged in and connected user, someone you know
	                //alert('logged in and connected user');
	        }
	});
	FB.Canvas.setAutoResize();
};
(function() {
	var e = document.createElement('script');
	e.type = 'text/javascript';
	e.src = document.location.protocol +
	'//connect.facebook.net/en_US/all.js';
	e.async = true;
	document.getElementById('fb-root').appendChild(e);
}());

function wallPost(name, caption, description, image, link) {
	var publish = {
		method: 'stream.publish',
		name: name,
		caption: caption,
		description: description,
		link: link,
		picture: image
	}
	
	var postCompleteFunc = function(response) {
		var flashObj = getFlashObject();
		flashObj.wallPostComplete();
	};

	FB.ui( publish, postCompleteFunc );
}

function request(title, message, data, to) {
	var request = {
		method: 'apprequests',
		title: title,
		message: message,
		data: data
	}
	if (to != "all") {
		request['to'] = to;
	}
	
	var requestCompleteFunc = function(response) {
		var flashObj = getFlashObject();
		flashObj.requestComplete();
	}
	
	FB.ui(request, requestCompleteFunc);
}