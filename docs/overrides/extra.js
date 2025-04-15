document.addEventListener("DOMContentLoaded", function () {
  const logo = document.querySelector(".md-header__button.md-logo");
  if (logo) {
    logo.onclick = () => {
      window.location.href = "https://www.unitn.it/";
    };
  }
});