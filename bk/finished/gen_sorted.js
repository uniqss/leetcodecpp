const fs = require('fs')

let problems = [];
trim = function (dname) {
  const dt = require(`./${dname}.json`);
  const questions = dt.data.problemsetQuestionList.questions;
  questions.forEach(function (qi, idx) {
    let problem = {};
    problem.topics = [];
    qi.topicTags.forEach(function (item, idx) {
      problem.topics.push(item.slug);
    });
    problem.topics.sort();
    problem.topic_str = "";
    problem.topics.forEach(function (topic, idx) {
      problem.topic_str = problem.topic_str + topic + ", ";
    });
    problem.frontendQuestionId = qi.frontendQuestionId;
    problem.titleSlug = qi.titleSlug;
    problem.acRate = qi.acRate;
    problem.difficulty = qi.difficulty;
    // const line = `${qi.frontendQuestionId}, https://leetcode.cn/problems/${qi.titleSlug}/, ${String(qi.acRate * 100).substring(0, 4)}, ${qi.difficulty}, ${topic}\n`;
    // console.log(line);
    // lines.push(line);
    problems.push(problem);
    // console.log(`${qi.frontendQuestionId}, https://leetcode.cn/problems/${qi.titleSlug}/description/, ${qi.acRate}, ${qi.difficulty}, ${topic}`)
  })
}

for (i = 1; i <= 4; ++i) {
  // trim(`${i}`);
  trim(`algorithm_${i}`);
}

// sort by its labels
function compareFn(a, b) {
  if (a.topic_str < b.topic_str) {
    return -1;
  }
  if (a.topic_str > b.topic_str) {
    return 1;
  }
  return 0;
}

fname = "finished_algorithm_sorted.csv"
problems.sort(compareFn);


fs.writeFileSync(fname, "");
problems.forEach(function (qi, idx) {
  const line = `${qi.frontendQuestionId}, https://leetcode.cn/problems/${qi.titleSlug}/, ${String(qi.acRate * 100).substring(0, 4)}, ${qi.difficulty}, ${qi.topic_str}\n`;
  fs.writeFile(fname, line, { flag: 'a+' }, err => { });
  // console.log(line);
});
