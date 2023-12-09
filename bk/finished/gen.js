const fs = require('fs')

let lines = [];
trim = function (dname) {
    const dt = require(`./${dname}.json`);
    const questions = dt.data.problemsetQuestionList.questions;
    questions.forEach(function (qi, idx) {
        topic = "";
        qi.topicTags.forEach(function (item, idx) {
            topic = topic + item.slug + ", "
        })

        const line = `${qi.frontendQuestionId}, https://leetcode.cn/problems/${qi.titleSlug}/, ${String(qi.acRate * 100).substring(0, 4)}, ${qi.difficulty}, ${topic}\n`;
        console.log(line);
        lines.push(line);
        // console.log(`${qi.frontendQuestionId}, https://leetcode.cn/problems/${qi.titleSlug}/description/, ${qi.acRate}, ${qi.difficulty}, ${topic}`)
    })
}

trim('1');
trim('2');
trim('3');
trim('4');

fname = "finished.csv"
lines.forEach(function (line, idx) {
    fs.writeFile(fname, line, { flag: 'a+' }, err => { });
    // console.log(line);
});
