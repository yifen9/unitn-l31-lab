document.addEventListener("DOMContentLoaded", function () {
  const logo = document.querySelector(".md-header__button.md-logo");
  if (logo) {
    logo.setAttribute("title", "Visit UniTrento homepage");
    logo.style.cursor = "pointer";

    logo.addEventListener("click", function (event) {
      event.preventDefault();
      window.open("https://www.unitn.it/", "_blank");
    });
  }
});