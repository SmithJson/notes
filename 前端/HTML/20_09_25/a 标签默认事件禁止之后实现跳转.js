let domArr = document.getElementsByTagName('a');

[...domArr].forEach(item => {
	item.addEventListener('click', function (e) {
		e.preventDefault();
		hocation.href = this.href;
	});
});
