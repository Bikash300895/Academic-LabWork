function search(str) {
    $('#dd').addClass('show');
    console.log(str);

    $('#dd_content').load('/students/find?key=' + str);
}
