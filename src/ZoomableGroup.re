[@bs.module "react-simple-maps"]
external zoomableGroupClass : ReasonReact.reactClass = "ZoomableGroup";

[@bs.deriving abstract]
type jsProps = {
  zoom: int,
  center: array(int),
  disablePanning: bool,
  style: ReactDOMRe.Style.t,
};

let make =
    (
      ~zoom=1,
      ~center=[|0, 0|],
      ~disablePanning=false,
      ~style=ReactDOMRe.Style.make(),
      ~onMoveStart=?,
      ~onMoveEnd=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=zoomableGroupClass,
    ~props=
      Js.Obj.assign(
        Obj.magic(jsProps(~zoom, ~center, ~disablePanning, ~style)),
        {"onMoveStart": onMoveStart, "onMoveEnd": onMoveEnd},
      ),
    children,
  );
