const ps = new Promise((resolve, reject) => {
	reject("Error");
});

ps
	.then((data) => {
		console.log(data);
	}).catch((e) => {
		console.log(e, 1);
	}).then(() => {
		console.log("Success-2");
	}, () => {
		console.log("Erro-2");
	});

const promise = new Promise((resolve, reject) => {
	reject("error");
	// resolve("success2");
});
promise
	.then(res => {
		console.log("then: ", res);
	}).then(res => {
		console.log("then: ", res);
	}).catch(err => {
		console.log("catch: ", err);
	}).then(res => {
		console.log("then: ", res);
	})
