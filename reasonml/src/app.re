open ReactRouter;

module Header = {
  let component = ReasonReact.statelessComponent "Header";
  let make _children => {
    ...component,
    render: fun self => <div> (ReasonReact.stringToElement "Hola soy el header") </div>
  };
};

module Movies = {
  let component = ReasonReact.statelessComponent "Movies";
  let make _children => {
    ...component,
    render: fun self => <div> (ReasonReact.stringToElement "Movies") </div>
  };
};

let getMovies () => <Movies />;

let component = ReasonReact.statelessComponent "App";

let make _children => {
  ...component,
  render: fun self =>
    <BrowserRouter>
      <div>
        <Header />
        <div> <Route exact=true path="/" component=getMovies /> </div>
      </div>
    </BrowserRouter>
};
