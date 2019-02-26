$(document).ready(function() {
    // Use a "/test" namespace.
    // An application can open a connection on multiple namespaces, and
    // Socket.IO will multiplex all those connections on a single
    // physical channel. If you don't care about multiple channels, you
    // can set the namespace to an empty string.
    namespace = '/test2';
    // Connect to the Socket.IO server.
    // The connection URL has the following format:
    //     http[s]://<domain>:<port>[/<namespace>]
    var socket = io.connect(location.protocol + '//' + document.domain + ':' + location.port + namespace);
    socket.on('my_response', function(msg) {
        $('#log').append('<br>' + $('<div/>').text(msg.first_name + ' ' + msg.last_name + ' from ' + msg.school + ' studying ' +  msg.program + ' taking ' + msg.courses).html());
    });
    $('form#search').submit(function(event) {
        socket.emit('search', {first_name_search: $('#first_name_search').val()
            ,first_name_bool: $('#first_name_bool').is(':checked')
            ,last_name_search: $('#last_name_search').val()
            ,last_name_bool: $('#last_name_bool').is(':checked')
            ,school_search: $('#school_search').val()
            ,school_bool: $('#school_bool').is(':checked')
            ,program_search: $('#program_search').val()
            ,program_bool: $('#program_bool').is(':checked')
            ,course_search: $('#course_search').val()
            ,course_bool: $('#course_bool').is(':checked')
        });
        return false;
    });
    // Handlers for the different forms in the page.
    // These accept data from the user and send it to the server in a
    // variety of ways

});
